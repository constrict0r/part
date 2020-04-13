Boolean value indicating if unify the items found on the **items_b** variable into an **unified_b** collection.

If set to *true* this role will build an **unified_b** collection from the items found on **items_b**.

This variable is used together with the **items_b**, **expand_b** and **titles_b** variables.

This variable is *false* by default.

.. substitution-code-block:: bash

 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| \
     -e "secondary=true items_b='/home/username/extra-packages.yml' titles_b='|DEFAULT_VAR_NAME|'"

To prevent any unexpected behaviour, it is recommended to always specify this variable when calling this role.