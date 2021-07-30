# navigate 
[![npm](https://img.shields.io/npm/v/@uni/navigate.svg)](https://www.npmjs.com/package/@uni/navigate)

Route navigation capability implementation.

## Support

<img alt="browser" src="https://gw.alicdn.com/tfs/TB1uYFobGSs3KVjSZPiXXcsiVXa-200-200.svg" width="25px" height="25px" /> <img alt="miniApp" src="https://gw.alicdn.com/tfs/TB1bBpmbRCw3KVjSZFuXXcAOpXa-200-200.svg" width="25px" height="25px" /> <img alt="wechatMiniprogram" src="https://img.alicdn.com/tfs/TB1slcYdxv1gK0jSZFFXXb0sXXa-200-200.svg" width="25px" height="25px" /> <img alt="bytedanceMicroApp" src="https://gw.alicdn.com/tfs/TB1jFtVzO_1gK0jSZFqXXcpaXXa-200-200.svg" width="25px" height="25px" />

## Install

```bash
$ npm install @uni/navigate --save
```

## Usage

```js
import navigate from '@uni/navigate';

// How to use it in quickapp
// import chooseImage from '@uni/navigate/lib/quickapp;

navigate.push({
  url: 'https://www.taobao.com/'
}).then(() => {
});

navigate.back().then(() => {
});

navigate.go({
  step: -1
}).then(() => {
});

navigate.replace({
  url: 'https://www.taobao.com/'
}).then(() => {
});

navigate.reLaunch({
  url: 'https://www.taobao.com/'
}).then(() => {
});
```

## Methods

### `push(options)`

#### Arguments
| Property         | Type      | Description                                                                        | required | Default |
| ---------------- | --------- | ---------------------------------------------------------------------------------- | :------: | :-----: |
| options          | `object`  | Push function arguments                                                            |   true   |    -    |
| options.url      | `string`  | The page URL.                                                                      |   true   |    -    |
| options.success | `Function`  | The callback function for a successful API call | false | - |
| options.fail | `Function`  | The callback function for a failed API call | false | - |
| options.complete | `Function`  | The callback function used when the API call completed (always executed whether the call succeeds or fails) | 否 | - |

### `back(options)`

#### Arguments
| Property         | Type      | Description                                                                        | required | Default |
| ---------------- | --------- | ---------------------------------------------------------------------------------- | :------: | :-----: |
| options          | `object`  | Pop function arguments                                                             |  false   |    -    | 
| options.success | `Function`  | The callback function for a successful API call | false | - |
| options.fail | `Function`  | The callback function for a failed API call | false | - |
| options.complete | `Function`  | The callback function used when the API call completed (always executed whether the call succeeds or fails) | 否 | - |

### `go(options)`

#### Arguments
| Property         | Type      | Description                                                                                                      | required | Default |
| ---------------- | --------- | ---------------------------------------------------------------------------------------------------------------- | :------: | :-----: |
| options          | `object`  | Go function arguments                                                                                            |   true   |    -    |
| options.step     | `number`  | The number of forward steps is positive and only supports the web, and the number of backward steps is negative. |   true   |    -    |
| options.success | `Function`  | The callback function for a successful API call | false | - |
| options.fail | `Function`  | The callback function for a failed API call | false | - |
| options.complete | `Function`  | The callback function used when the API call completed (always executed whether the call succeeds or fails) | 否 | - |

### `replace(options)`

#### Arguments
| Property         | Type      | Description                                                                                                      | required | Default |
| ---------------- | --------- | ---------------------------------------------------------------------------------------------------------------- | :------: | :-----: |
| options          | `object`  | Go function arguments                                                                                            |   true   |    -    |
| options.url     | `number`  | The page URL.                              |   true   |    -    |
| options.success | `Function`  | The callback function for a successful API call | false | - |
| options.fail | `Function`  | The callback function for a failed API call | false | - |
| options.complete | `Function`  | The callback function used when the API call completed (always executed whether the call succeeds or fails) | 否 | - |

### `reLaunch(options)`

#### Arguments
| Property         | Type      | Description                                                                                                      | required | Default |
| ---------------- | --------- | ---------------------------------------------------------------------------------------------------------------- | :------: | :-----: |
| options          | `object`  | Go function arguments                                                                                            |   true   |    -    |
| options.url     | `number`  | The page URL.                              |   true   |    -    |
| options.success | `Function`  | The callback function for a successful API call | false | - |
| options.fail | `Function`  | The callback function for a failed API call | false | - |
| options.complete | `Function`  | The callback function used when the API call completed (always executed whether the call succeeds or fails) | 否 | - |


```jsx | inline
  import React from 'react';
  export default class Home extends React.Component {
    componentDidMount() {
      document.querySelector('.__dumi-default-menu').style.background = '#fff';
      if (location.search.split(/[?&]/).some(i => i === 'clear=1')) {
        document.querySelector('.__dumi-default-navbar').style.display = 'none';
        document.querySelector('.__dumi-default-layout').classList = [];
        document.querySelector('.__dumi-default-menu').style.display = 'none';
        document.querySelector('.__dumi-default-layout-toc').style.display = 'none';
        document.querySelector('.__dumi-default-layout-content').querySelector('.markdown').querySelector('h1').style.marginTop = 0;
        parent.postMessage && parent.postMessage(parent.postMessage({ event: 'syncIframeHeight', height: document.querySelector('.__dumi-default-layout-content').offsetHeight }, '*'));
      }
    }

    render() {
      return null;
    }
  }
```
