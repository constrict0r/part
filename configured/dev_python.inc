- direnv

 - Enable *direnv* command on *~/.bashrc* file.

- emacs

 - Set `elpy <https://is.gd/tPU9gM>`_ plugin.

 - Set `tox.el <https://is.gd/hUqDMw>`_ plugin.

 - Set keybindings:

  - C-c C-c: Evaluates the current script.

  - C-RET (Enter): Evaluates the curren statement (current line plus the
     following nested line).

  - C-c C-z: Switches between your script and the interactive shell.

  - C-c C-d: Displays documentation for the thing under cursor (function or
    module). The documentation will pop in a different buffer, can be closed
    with *q*.

  - C-c C-t: Run pytest tests.

  - M-x tox-current-test: Run tox tests for current test.

  - M-x tox-current-class: Run tox tests for current class.

  - M-x pdb: Run PDB on a new window.

  - C-x: Set breakpoint on current line.

- `poetry <https://poetry.eustace.io/>`_

 - Add poetry path to the *~/.profile* file to maintain dependecies aisolated.

- `python3-virtualenv <https://virtualenv.pypa.io/en/latest/>`_

 - Enable elpy virtual enviroments on the *~/.bashrc* file.