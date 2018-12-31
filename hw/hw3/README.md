```Dockerfile
FROM alpine:latest

WORKDIR /usr/src/app

RUN apk add nodejs npm git; git clone https://github.com/KU-Cloud/hello-docker.git; cp hello-docker/* ./; npm install;

EXPOSE 8080

CMD ["npm", "start", "--"]
```

1번째 줄 : 어떤 이미지를 기반으로 이미지를 생성할지 설정. 여기서는 alpine 최신 버전을 기반으로 생성

2번째 줄 : RUN, CMD, ENTRYPOINT의 명령이 실행될 디렉터리를 설정. 여기서는 /usr/src/app 디렉터리로 설정

3번째 줄 :
- nodejs, npm, git을 설치 한다.
- KU-Cloud/hello-docker의 Github 레파지토리를 /usr/src/app로 클론한다.
- hello-docker폴더 안에 있는 모든 파일을 /usr/src/app로 옮긴다.
- 웹 서버를 구동할 때 필요한 NPM 페키지들을 설치한다.

4번째 줄 : 호스트와 연결할 포트 번호를 설정.

5번째 줄 : 컨테이너가 시작되었을 때 실행할 커맨드. 여기서는 npm start 명령어를 통해 웹 서버를 실행한다.