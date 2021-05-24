# Simple client-server app #

Build server:

```
gcc server.c error_processing.c -W -Wall -Werror -std=c99 -o server
```

Build client:

```
gcc client.c error_processing.c -W -Wall -Werror -std=c99 -o client
```

Or use make:

``` makefile
make all    #build client and server
make server #build server app
make client #build client app
```