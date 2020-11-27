## How to create documentation

- Install `mkdocs` and other dependencies.
```
pip install -r requirements.txt
``` 

- Create a `markdown` file under `docs/\` directory and update the `mkdocs.yml` to link that file.

- Build the docs and run the server locally.
```
mkdocs build && mkdocs serve 

# stop the server by -> (ctrl + c) 
```
