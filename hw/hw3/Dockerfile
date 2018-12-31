FROM alpine:latest

WORKDIR /usr/src/app

RUN apk add nodejs npm git; git clone https://github.com/KU-Cloud/hello-docker.git; cp hello-docker/* ./; npm install;

EXPOSE 8080

CMD ["npm", "start", "--"]