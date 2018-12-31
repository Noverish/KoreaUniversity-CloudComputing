

## Setup
```shell
$ docker build -t recorder:0.1 ./recorder
$ docker build -t handler:0.1 ./handler

$ docker volume create world

$ docker run --rm -d --mount src=world,dst=/data recorder:0.1
$ docker run --rm -d --mount src=world,dst=/data handler:0.1
```

## record strings

```shell
$ curl http://172.17.0.2:8080/what_you_want_to_record
```

## check records
```shell
$ cat /var/lib/docker/volumes/world/_data/.total
```
