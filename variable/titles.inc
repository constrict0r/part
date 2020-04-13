Name used as index to load items from files and URLs.

This variable is used when the **expand** variable is set to *true*.

This variable is empty by default.

.. substitution-code-block:: bash

 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| \
     -e "expand=true items='/home/username/my-config.yml' titles='|DEFAULT_VAR_NAME|'"

To prevent any unexpected behaviour, it is recommended to pass this variable as an empty list *[]* when not used.