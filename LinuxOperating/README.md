# 安装git
yum install git

# 安装AnkiServer
```
    ./ankiserverctl.py debug
    Traceback (most recent call last):
    File "./ankiserverctl.py", line 169, in <module>
        main()
    File "./ankiserverctl.py", line 151, in main
        startsrv(sys.argv[2], True)
    File "./ankiserverctl.py", line 42, in startsrv
        subprocess.call( ["paster", "serve", configpath], shell=False)
    File "/usr/lib64/python2.7/subprocess.py", line 524, in call
        return Popen(*popenargs, **kwargs).wait()
    File "/usr/lib64/python2.7/subprocess.py", line 711, in __init__
        errread, errwrite)
    File "/usr/lib64/python2.7/subprocess.py", line 1327, in _execute_child
        raise child_exception
    OSError: [Errno 2] No such file or directory
```
安装依赖
pip install webob PasteDeploy PasteScript sqlalchemy simplejson
./ankiserverctl.py debug
添加用户
./ankiserverctl.py adduser wangyang

./ankiserverctl.py start

windows配置自定义的服务器

```
    import anki.sync
    anki.sync.SYNC_BASE = 'http://47.93.201.74:27701/'
    anki.sync.SYNC_MEDIA_BASE = 'http://47.93.201.74:27701/msync/'
```


