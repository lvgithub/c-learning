## mac 下 gdb 安装

1. `brew install gdb` 安装

2. 这时候直接使用gdb的时候，会报错 `Unable to find Mach task port for process-id 23330:`,我们需要通过证书授权

3. 参考[macOS 对 gdb 进行代码签名](https://cloud.tencent.com/developer/article/1047110)进行安装，会有如下问题

    * 生成证书的时候，报错 `位置错误`,这时候，把存放证书地址，选择：`系统` 改为登录，然后手动移动到系统中
    * 10.14 之前的系统直接执行 `codesign -fs gdb-cert $(which gdb)` 命令即可，之后的需要先创建一个 gdb-entitlement.xml文件
    ``` xml
    <?xml version="1.0" encoding="UTF-8"?>
    <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
    <plist version="1.0">
    <dict>
        <key>com.apple.security.cs.debugger</key>
        <true/>
    </dict>
    </plist>
    </pre>
    ```
    然后执行
    ```shell
    codesign --entitlements gdb-entitlement.xml -fs gdb-cert $(which gdb)
    ```

4. 愉快的使用 gdb 调试