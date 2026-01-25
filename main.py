import random
import sys
import os
import pathlib
import subprocess
from datetime import datetime


def generate_values(count: int, min_val: int, max_val: int) -> list[int]:
    return random.sample(range(min_val, max_val + 1), count)


def build_command(values: list[int], platform: str) -> str:
    arg_str = " ".join(map(str, values))
    checker = "checker_mac" if platform == "darwin" else "checker_linux"
    push_swap_cmd = f'ARG="{arg_str}"; ./push_swap $ARG'
    checker_cmd = f'./{checker} $ARG'
    return f'{push_swap_cmd} | {checker_cmd}'


def get_user_input() -> tuple[int, int, int, bool]:
    count = int(input("Enter the number of values (default 100): ") or 100)
    min_val = int(input("Enter minimum value (default -10000): ") or -10000)
    max_val = int(input("Enter maximum value (default 10000): ") or 10000)
    execute = input("Execute the command or just print it? (E/p): ") in 'eE'
    return count, min_val, max_val, execute


def validate_input(count: int, min_val: int, max_val: int):
    if count < 1:
        raise ValueError("Count must be at least 1.")
    if min_val >= max_val:
        raise ValueError("Minimum value must be less than maximum value.")
    if count > (max_val - min_val + 1):
        raise ValueError("Count is too large for the given range.")
    if count > 2**16:
        raise ValueError("Count is too large (>65536).")
    if min_val < -2**31 or max_val > 2**31 - 1:
        raise ValueError("Values must be within 32-bit integer range.")


def recompile_push_swap():
    print("Recompiling push_swap...")
    subprocess.run(
        ["make", "re"],
        check=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )
    subprocess.run(
        ["make", "-C", "checker", "re"],
        check=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )


def execute_command(cmd: str):
    os.system(cmd)


def sb_execute_command(cmd: list[str]):
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.stderr:
        return result.stderr.strip()
    return result.stdout.strip()


def benchmark(count: int, test_name: str, results: list):
    s = f"{'='*70}\n"
    s += f"TEST: {test_name}\n"
    s += f"Elements count: {count}\n"
    s += f"Start time: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n"
    s += f"{'='*70}\n\n"

    for run in range(1, 6):
        arg_str = " ".join(map(str, generate_values(count, -2**31, 2**31 - 1)))

        checker_cmd = (
            f'ARG="{arg_str}"; '
            f'./push_swap $ARG | ./checker_linux $ARG'
        )
        ops_cmd = f'ARG="{arg_str}"; ./push_swap $ARG | wc -l'

        checker_out = sb_execute_command(
            ["/bin/bash", "-c", checker_cmd]
        ).strip()

        ops_out = sb_execute_command(
            ["/bin/bash", "-c", ops_cmd]
        ).strip()

        results.append({
            "count": count,
            "run": run,
            "checker": checker_out,
            "operations": int(ops_out),
            "args": arg_str,
            "checker_cmd": checker_cmd,
            "ops_cmd": ops_cmd
        })

        s += f"{'-'*50}\n"
        s += f"Run #{run}\n"
        s += f"{'-'*50}\n"

        s += "Arguments:\n"
        s += f"  {arg_str}\n\n"

        s += "Executed commands:\n"
        s += "  Checker:\n"
        s += f"    {checker_cmd}\n"
        s += "  Operations count:\n"
        s += f"    {ops_cmd}\n\n"

        s += "Checker output:\n"
        s += f"  {checker_out}\n\n"

        s += "Operations:\n"
        s += f"  {ops_out}\n\n"

    return s


def build_summary_table(results: list) -> str:
    s = "\n\nSUMMARY TABLE\n"
    s += "=" * 70 + "\n"
    s += f"{'COUNT':<8} {'RUN':<5} {'CHECKER':<10} {'OPERATIONS':<12}\n"
    s += "-" * 70 + "\n"

    is_newop = False
    for r in results:
        if r["count"] == 500 and not is_newop:
            s += "-" * 70 + "\n"
            is_newop = True
        s += (
            f"{r['count']:<8} "
            f"{r['run']:<5} "
            f"{r['checker']:<10} "
            f"{r['operations']:<12}\n"
        )
    s += "=" * 70 + "\n"
    return s


def run_benchmark(filename: str = "benchmark_log.txt"):
    print("Running benchmark test...\n")

    results = []
    log = "PUSH_SWAP BENCHMARK LOG\n"
    log += f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n"

    log += benchmark(
        100,
        "100 values (limit: 700 ops)",
        results
    )

    log += benchmark(
        500,
        "500 values (limit: 5500 ops)",
        results
    )

    log += build_summary_table(results)

    with open(filename, "w", encoding="utf-8") as f:
        f.write(log)

    print(f"Benchmark finished → {filename}\n\n")


def check_errors(filename: str = "errors_log.txt"):
    result = "Checking for errors...\n\n"

    result += "Test 1: Duplicates\n"
    result += "Command:\n"
    result += "./push_swap 0 1 2 2\n"
    result += "Result: "
    result += sb_execute_command(["./push_swap", "0", "1", "2", "2"]) + "\n"
    result += "=" * 40 + "\n\n"

    result += "Test 2: Non-integer input\n"
    result += "Command:\n"
    result += "./push_swap 0 1 a\n"
    result += "Result: "
    result += sb_execute_command(["./push_swap", "0", "1", "a"]) + "\n"
    result += "=" * 40 + "\n\n"

    result += "Test 3: Out of range input +\n"
    result += "Command:\n"
    result += f"./push_swap 0 1 {2**32}\n"
    result += "Result: "
    result += sb_execute_command(["./push_swap", "0", "1", str(2**32)]) + "\n"
    result += "=" * 40 + "\n\n"

    result += "Test 4: Out of range input -\n"
    result += "Command:\n"
    result += f"./push_swap 0 1 {-(2**32)}\n"
    result += "Result: "
    result += sb_execute_command(["./push_swap", "0", "1", str(-(2**32))])
    result += "\n"
    result += "=" * 40 + "\n\n"

    with open(filename, "w", encoding="utf-8") as f:
        f.write(result)
    print(f"Error checking finished → {filename}\n\n")


def memory_leak_check():
    values = generate_values(500, -2**31, 2**31 - 1)
    valgrind_cmd = (
        f'ARG="{" ".join(map(str, values))}"; '
        f'valgrind --leak-check=full ./push_swap $ARG | '
        f'tail -n +$((n+1)) | grep "HEAP SUMMARY"'
    )
    execute_command(valgrind_cmd)


def param_main():
    if not pathlib.Path("./push_swap").is_file():
        recompile_push_swap()

    match sys.argv[1]:
        case "--benchmark" | "-b":
            run_benchmark()
        case "--check-errors" | "-c":
            check_errors()
        case "--all" | "-a":
            run_benchmark()
            check_errors()
        case "--memory-leak" | "-m":
            memory_leak_check()
        case "--help" | "-h":
            print("Usage:")
            print("  python main.py            # Run interactive mode")
            print("  python main.py --benchmark|-b   # Run benchmark tests")
            print(
                "  python main.py --check-errors|-c # Check for error handling"
            )
            print("  python main.py --help|-h        # Show this help message")


def main():
    if len(sys.argv) > 1:
        param_main()
        return

    if sys.platform not in ["linux", "darwin"]:
        print("This script is only supported on Linux or macOS.")
        return

    count, min_val, max_val, execute = get_user_input()
    validate_input(count, min_val, max_val)

    values = generate_values(count, min_val, max_val)

    cmd = build_command(values, sys.platform)

    if not execute:
        print("Generated command:")
        print(cmd)
        return

    checker_file = "checker_"
    checker_file += "mac" if sys.platform == "darwin" else "linux"
    if not pathlib.Path(f"./{checker_file}").is_file():
        raise FileNotFoundError(
            f"{checker_file} binary not found. Please compile it first."
        )

    if not pathlib.Path("./push_swap").is_file():
        recompile_push_swap()
    else:
        if input(
            "Write 'y' to recompile push_swap, or any other key to continue: "
        ).lower() == 'y':
            recompile_push_swap()

    print("-" * 40)
    print("Executing checker...")
    execute_command(cmd)

    print("-" * 40)
    print("Counting number of operations...")
    push_swap_only_cmd = (
        f'ARG="{" ".join(map(str, values))}"; '
        f'./push_swap $ARG | wc -l'
    )
    execute_command(push_swap_only_cmd)
    print("-" * 40, "\n")

    if input("Print all operations? (y/N): ").lower() == 'y':
        filename = input(
            "Press Enter to print operations or write <filename> to save: "
        )
        output_cmd = (
            f'ARG="{" ".join(map(str, values))}"; '
            f'./push_swap $ARG'
        )
        if filename:
            output_cmd += f" > {filename}"
            print(f"Operations saved to {filename}")
        execute_command(output_cmd)

    print("-" * 40)
    input("Check memory leaks with valgrind? (Press Enter to continue)")
    valgrind_cmd = (
        f'ARG="{" ".join(map(str, values))}"; '
        f'valgrind --leak-check=full ./push_swap $ARG | '
        f'tail -n +$((n+1)) | grep "HEAP SUMMARY"'
    )
    execute_command(valgrind_cmd)

    print("-" * 40)
    if input("Run benchmark test? (y/N): ").lower() == 'y':
        run_benchmark()


if __name__ == "__main__":
    main()
