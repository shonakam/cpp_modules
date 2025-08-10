import subprocess
import yaml
import pytest

def run_rpn(expr):
    proc = subprocess.run(
        ['../RPN', expr],
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    return proc.returncode, proc.stdout.strip(), proc.stderr.strip()

def load_testcases():
    with open('cases/testcases.yaml', 'r') as f:
        return yaml.safe_load(f)

@pytest.mark.parametrize("case", load_testcases())
def test_rpn(case):
    rc, out, err = run_rpn(case['expr'])

    if case['expected_stderr']:
        assert case['expected_stderr'] in err, f"Expected stderr: '{case['expected_stderr']}', but got: '{err}'"
    else:
        assert out == case['expected_stdout'], f"Expected stdout: '{case['expected_stdout']}', but got: '{out}'"
        assert err == ""
