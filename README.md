<p align="center">
  <a href="https://universal-api.js.org/">
    <img alt="Rax" src="https://img.alicdn.com/imgextra/i3/O1CN01lt5FH71VubB3j3Okd_!!6000000002713-2-tps-412-412.png" width="66">
  </a>
</p>

<p align="center">
Uni API 是一套支持小程序和 Web 容器的跨端 API 解决方案。
</p>

---

🎉 **多容器支持** 目前支持 Web、微信小程序、头条小程序、阿里小程序

🐂 **API 丰富** 覆盖 90+ API 实现

😯 **文档完善** 提供双语文档、丰富样例

0️⃣ **无框架依赖** 无框架依赖，纯原生实现，可以兼容任意框架

🚀 **极致体积** 支持按需加载，按环境剔除无用代码

👍🏻 **简易使用，快速接入** 提供完善的 Typescripts 声明，让你可以摆脱文档，沉浸编程

## 快速使用

```bash
$ npm install @uni/toast
```

```js
import { showToast } from '@uni/toast';

// string
showToast('Hi');

// object
showToast({
  content: 'hello',
  type: 'success',
  duration: 1000,
  success: () => {
    console.log('toast')
  }
});

// promise
showToast({
  content: 'hello',
  type: 'success',
  duration: 1000,
}).then(() => {});
```

## 文档
官方站点：[https://universal-api.js.org/](https://universal-api.js.org/)

## 示例

|微信小程序|支付宝小程序|
|--------|----------|
|<img src="https://img.alicdn.com/imgextra/i1/O1CN01upA1bP1CxpGb8qLPp_!!6000000000148-0-tps-662-662.jpg" width="200" height="200" />|<img src="https://gw.alicdn.com/imgextra/i3/O1CN01Ca6t2Q2AEpIXh4r0u_!!6000000008172-0-tps-1540-1906.jpg" width="200" height="250" />|

## 贡献代码
请首先阅读 [Rax 贡献代码指南](https://github.com/alibaba/rax/wiki/CONTRIBUTING)，了解基础的规范。

### 起步

```bash
$ git clone git@github.com:raxjs/universal-api.git
$ npm install
$ npm run build
```

### 调试 API
以 @uni/toast 为例：

```bash
$ npm run build toast
$ npm run build:demo
$ cd demos
$ npm i
$ npm run start # 启动项目，打开小程序 IDE 进行调试
```

然后使用小程序 IDE 即可开始调试:

<img height="400" src="https://gw.alicdn.com/imgextra/i3/O1CN01qDANFg1QRDiWoHzHr_!!6000000001972-0-tps-2048-1418.jpg">

### 更新版本
API package 版本统一维护在根目录下的api-config.js，以 @uni/toast 为例：

```js
module.exports = {
  toast: {
    path: 'src/packages/interactive/toast/src/index.ts',
    pkgInfo: [
      {
        version: '1.0.5',
        name: '@uni/toast',
      },
    ],
  },
}
```

| 参数 | 含义 |	默认值 |
|----|----|----|
|path|	在源文件的路径|	-|
|pkgInfo|	npm包的属性（同packagejson写法）|	-|
|needCommonUtil|	是否需要公共utils|	true|
|unNeedSplit|	是否需要安环境分包|	false|


大包版本需要更新根目录下的 package.json 的 version
### API 包列表

| NPM 包                             | 描述                                                         |
| ---------------------------------- | ------------------------------------------------------------ |
| @uni/apis | Uni API 大包 |
| @uni/env | 判断和获取运行时环境 |
| @uni/caniuse | 判断 API 是否可用 |
| @uni/application | 应用级 API，包括 getApp/getCurrentPages/getLaunchOptionsSync/offError/onError/onUnhandledRejection/offUnhandledRejection |
| @uni/canvas | 获取 canvas 绘图上下文 |
| @uni/accelerometer | 加速度监听与取消 |
| @uni/clipboard | 获取/设置系统剪贴板的内容 |
| @uni/system-info | 获取系统信息 |
| @uni/file | 文件操作相关 API |
| @uni/action-sheet | 显示操作菜单 |
| @uni/alert | alert 警告框 |
| @uni/confirm | 显示模态对话框 |
| @uni/element | 获取 DOM 节点的信息 |
| @uni/loading | 隐藏 loading 提示框 |
| @uni/toast | 通用弱提示 |
| @uni/intersection-observer | 用于推断某些节点是否可以被用户看见、有多大比例可以被用户看见 |
| @uni/location | 地理位置相关 API |
| @uni/image | 图片操作相关 API |
| @uni/navigate | 路由导航能力实现 |
| @uni/request | 用于发起网络请求 |
| @uni/storage | storage 相关API |
## 协议

[BSD License](https://github.com/raxjs/miniapp/blob/master/LICENSE)