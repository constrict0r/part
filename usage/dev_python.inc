Pytest
..............................................................

In order to run tests with pytest, execute the following steps:

- Inside your project's root folder, create a *tests* directory:

 .. code-block:: bash

  cd my-project
  mkdir tests

- Add your test file inside the *tests* folder, be sure to prefix it with the
  text *test_*, for example *test_my_test.py*.

 .. code-block:: bash

  touch tests/test_my_test.py

- Inside the test file add some test functions, each function name must be
  prefixed with the text *test_*:

 .. code-block:: bash

  def tests_ok():
      print('ok')

- Call pytest using the command:

 .. code-block:: bash

  python3 -m pytest tests/

Pytest with virtualenv
..............................................................

If you want to use a *virtualenv* for running your tests, from a terminal:

- Activate the virtual enviroment:

 .. code-block:: bash

  source bin/activate

- Then run the tests:

 .. code-block:: bash

  python3 -m pytest tests/

Pytest on Emacs
..............................................................

On emacs, you can use the following keybindings:

- C-c C-c: Execute current script.

- C-c C-t: Execute pytest tests.

- M-x tox-run-current-test: Execute current tox test.

- M-x tox-run-current-class: Execute current tox test suite.

For more keybinding available see the
`elpy documentation <https://elpy.readthedocs.io/en/latest/>`_.

Tox
..............................................................

In order to run tox, execute the following steps:

- Create a folder named *tests*.

- Add your tests to the created folder.

- On the root directory of your project, create a *tox.ini* file with the
  following contents:

 .. code-block:: bash

  [tox]
  skipsdist = True
  envlist = py{35}

  [testenv]
  deps =
    pytest
  commands =
    python3 -m pytest tests

- Finally call tox:

 .. code-block:: bash

  tox

Tox on Emacs
..............................................................

To run tox form emacs, step over the name of a test function and execute the
keybindings:

.. code-block:: bash

 M-x tox-current-test RET

Virtualenvs on Emacs
..............................................................

To make emacs automatically load a virtual enviroment when a file inside a
project is edited, follow the steps:

- Create a virtual enviroment inside *·/.virtualenvs*, for example name it
  *my_virtualenv*:

 .. code-block:: bash

   python3 -m venv ~/.virtualenvs/my_virtualenv

- Add a file named *.dir-locals.el* on the root directory of your project with
  the following content:

 .. code-block:: bash

  ;; Directory Local Variables

  ;; Activate 'my_virtualenv' virtual enviroment from emacs.
  ((nil . ((pyvenv-workon . "my_virtualenv"))))

Now if you open a file of your project the virtual enviroment *my_virtualenv*
will be enabled automatically.

PDB on Emacs
..............................................................

In order to run `pdb <https://docs.python.org/3/library/pdb.html>`_ from emacs
when using a virtual enviroment, execute the steps:

- Create your virtual enviroment:

 .. code-block:: bash

  python3 -m venv ~/.virtualenvs/my_virtualenv

- Copy **pdb3** from the system path to the newly created virtual enviroment:

 .. code-block:: bash

  cp /usr/bin/pdb3 ~/.virtualenvs/my_virtualenv/bin/pdb

- Edit the file *~/.virtualenvs/my_virtualenv/bin/pdb* and change the first
  line from:

 .. code-block:: bash

  #! /usr/bin/python3.5

- To:

 .. code-block:: bash

  #! /home/username/.virtualenvs/my_virtualenv/bin/python3

- If you are developing a python package, inside emacs and on first editing,
  install your package running:

 .. code-block:: bash

  M-x shell RET
  python setup.py install RET

- You can now use the following keybindings:

 .. code-block:: bash

  - M-x pdb: Run PDB on a new window.
  - C-x: Set breakpoint on current line.
  - c: Run up to the breakpoint.
  - n: Next line.
  - s: Explore (search) functions on current line.
  - p: Watch a variable.
  - w: Print out the stack.
  - u: Go up on the stack.
  - d: Go down on the stack.

Poetry
..............................................................................

In order to use `poetry <https://poetry.eustace.io/>`_ you will need a
**pyproject.toml** file similar to the following:

.. code-block:: python

 [tool.poetry]
 name = "my-project"
 version = "0.1.0"
 description = "My description"
 authors = ["username <username@protonmail.com>"]
 license="MIT"

 readme = "README.rst"
 homepage="https://gitlab.com/username/my-project"
 repository="https://gitlab.com/username/my-project"
 documentation="https://project.readthedocs.io"

 keywords = ["devel", "tools"]
 classifiers = [
     'Topic :: Software Development :: Devel Tools',
     'License :: OSI Approved :: MIT License',
 ]

 [tool.poetry.dev-dependencies]
 pytest = "^3.10"
 tox = "^3.14"

 [tool.poetry.dependencies]
 click = "^7.0"
 python = "^3.7"

 [tool.poetry.scripts]
 my-project = "my_project.cli:main"

 [tool.tox]
 legacy_tox_ini= """
 [tox]
 skipsdist = True
 envlist = py{37}

 [testenv]
 deps =
   poetry
   pytest
 commands =
   poetry install
   pytest
 """
 [build-system]
 requires = ["poetry>=0.12"]
 build-backend = "poetry.masonry.api"

And then run **poetry** as a **python3** module:

.. code-block:: python

 python3 -m poetry install