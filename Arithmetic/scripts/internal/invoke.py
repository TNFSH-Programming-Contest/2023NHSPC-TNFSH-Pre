import sys
import os
import subprocess

from util import check_file_exists, wait_process_success
from color_util import cprint, colors
from gen_data_parser import check_test_pattern_exists_in_list, test_name_matches_pattern
from test_exists import test_exists


INTERNALS_DIR = os.environ.get('INTERNALS')
SPECIFIC_TESTS = os.environ.get('SPECIFIC_TESTS')
SPECIFIED_TESTS_PATTERN = os.environ.get('SPECIFIED_TESTS_PATTERN')


if __name__ == '__main__':
    
    if len(sys.argv) != 3:
        from util import simple_usage_message
        simple_usage_message("<tests-dir> <gen-summary-file>")

    tests_dir = sys.argv[1]
    gen_summary_file = sys.argv[2]
    
    if not os.path.isdir(tests_dir):
        sys.stderr.write("The tests directory not found or not a valid directory: {}.\n".format(tests_dir))
        exit(4)
    check_file_exists(gen_summary_file, "The tests are not correctly generated.\n")
    
    with open(gen_summary_file) as gsf:
        test_name_list = [line.split()[0] 
                            for line in map(str.strip, gsf.readlines())
                            if line and not line.startswith("#")]
    
    if SPECIFIC_TESTS == "true":
        check_test_pattern_exists_in_list(test_name_list, SPECIFIED_TESTS_PATTERN)
        test_name_list = filter(lambda test_name : test_name_matches_pattern(test_name, SPECIFIED_TESTS_PATTERN), test_name_list)

    missing_tests = []
    available_tests = []
    for test_name in test_name_list:
        if test_exists(tests_dir, test_name):
            available_tests.append(test_name)
        else:
            missing_tests.append(test_name)
    
    if missing_tests:
        cprint(colors.WARN, "Missing tests: "+(", ".join(missing_tests)))
    
    for test_name in available_tests:
        command = [
            'bash',
            os.path.join(INTERNALS_DIR, 'invoke_test.sh'),
            tests_dir,
            test_name,
        ]
        wait_process_success(subprocess.Popen(command))

    if missing_tests:
        cprint(colors.WARN, "Missing {} {}!".format(len(missing_tests), "tests" if len(missing_tests)!=1 else "test"))

