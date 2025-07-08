import signal
import sys

from test_segv import test_segv


def handle_signal():
    print("sup?", flush=True)
    sys.exit(1)


print("hello")
signal.signal(signal.SIGSEGV, handle_signal)
test_segv()
print("bye")
