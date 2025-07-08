## installation

```sh
pip install -e .
```

## run

```sh
python test.py
```

Use strace to observe that the program enters an infinite SIGSEGV-handling recursion.
