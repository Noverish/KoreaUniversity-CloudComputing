from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import os

file_path = '/data/.total'
cache_path = '/data/.last'


def touch_file(path):
    parent_path = os.path.abspath(os.path.join(path, os.pardir))

    if not os.path.isdir(parent_path):
        os.makedirs(parent_path)

    if not os.path.exists(path):
        with open(path, 'w'):
            pass


def read(path):
    with open(path, 'r') as f:
        return f.read()


def write(path, s):
    with open(path, 'w') as f:
        f.write(s)


def get_curr_millis():
    return int(round(time.time() * 1000))


if __name__ == '__main__':
    class RequestHandler(BaseHTTPRequestHandler):
        def do_GET(self):
            touch_file(file_path)
            touch_file(cache_path)

            input_string = self.path[1:]
            curr_millis = get_curr_millis()
            save_string = '{},{}'.format(curr_millis, input_string)
            print(save_string)

            write(cache_path, save_string)

            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            self.wfile.write(bytes(save_string, "utf8"))
            return


    print('Start Server!!')
    httpd = HTTPServer(("", 8080), RequestHandler)
    httpd.serve_forever()
