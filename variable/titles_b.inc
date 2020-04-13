Name used as index to load items from files and URLs.

This variable is used when the **expand_b** variable is set to *true*.

This variable is empty by default.

.. substitution-code-block:: bash

 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| \
     -e "expand_b=true items_b='/home/username/my-config.yml' titles_b='|DEFAULT_VAR_NAME|'"