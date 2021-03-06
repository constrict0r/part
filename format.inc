When passing configuration files to this role as parameters, it's recommended
to add a *.yml* or *.yaml* extension to the each file.

It is also recommended to add three dashes at the top of each file:

.. code-block:: bash

 ---

You can include in the file the variables required for your tasks:

.. substitution-code-block:: bash

 ---
 |DEFAULT_VAR_NAME|:
   - |DEFAULT_VAR_VALUE|

If you want this role to load list of items from files and URLs you can set
the **expand** variable to *true*:

.. substitution-code-block:: bash

 ---
 |DEFAULT_VAR_NAME|: /home/username/my-config.yml

 expand: true

If the expand variable is *false*, any file path or URL found will be treated
like plain text.