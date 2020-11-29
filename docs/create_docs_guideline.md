## How to create documentation

- Install `mkdocs` and other dependencies.
```
pip install -r requirements.txt
``` 

- Create a `markdown` file under `docs/\` directory and update the `mkdocs.yml` to link that file.

- Build the docs.
```
mkdocs build
```

- Run the server locally and review the changes.
```
mkdocs serve 

# stop the server by -> (ctrl + c) 
```