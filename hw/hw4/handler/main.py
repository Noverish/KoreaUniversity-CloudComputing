import os
import time

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


def append(path, s):
    with open(path, 'a') as f:
        f.write(s)


def get_curr_millis():
    return int(round(time.time() * 1000))


if __name__ == '__main__':
    while True:
        touch_file(file_path)
        touch_file(cache_path)

        last_cache = read(cache_path).strip().split('\n')[-1]
        last_record = read(file_path).strip().split('\n')[-1]

        if last_cache != '':
            if last_cache != last_record:
                append(file_path, last_cache + '\n')
                print('Read \'{}\' from cache'.format(last_cache))

        time.sleep(0.1)
