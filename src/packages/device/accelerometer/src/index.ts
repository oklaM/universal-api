import { isMiniApp, isWeChatMiniProgram, isByteDanceMicroApp, isWeb } from '@uni/env';
import aliMiniAppModule from './ali-miniapp/index';
import weChatModule from './wechat-miniprogram/index';
import bytedanceModule from './bytedance-microapp/index';
import webModule from './web/index';
import { Callback } from './types';

export const onChange = (cb: Callback) => {
  if (isWeChatMiniProgram) {
    return weChatModule.onChange(cb);
  } else if (isByteDanceMicroApp) {
    return bytedanceModule.onChange(cb);
  } else if (isMiniApp) {
    return aliMiniAppModule.onChange(cb);
  } else if (isWeb) {
    return webModule.onChange(cb);
  } else {
    throw new Error('@uni/apis：Accelerometer暂不支持');
  }
};
export const offChange = (cb?: Callback) => {
  if (isWeChatMiniProgram) {
    return weChatModule.offChange(cb);
  } else if (isByteDanceMicroApp) {
    return bytedanceModule.offChange(cb);
  } else if (isMiniApp) {
    return aliMiniAppModule.offChange(cb);
  } else if (isWeb) {
    return webModule.onChange(cb);
  } else {
    throw new Error('@uni/apis：Accelerometer暂不支持');
  }
};
export default {
  onChange,
  offChange,
};
