import { isMiniApp, isDingdingMiniapp, isWeChatMiniProgram, isByteDanceMicroApp } from 'universal-env';
import aliMiniAppModule from './ali-miniapp/index';
import weChatModule from './wechat-miniapp/index';
import bytedanceModule from './byte-miniapp/index';

const getImageInfo = (() => {
  if (isWeChatMiniProgram) {
    return weChatModule;
  } else if (isByteDanceMicroApp) {
    return bytedanceModule;
  } else if (isMiniApp || isDingdingMiniapp) {
    return aliMiniAppModule;
  } else {
    throw new Error('evapi：getImageInfo暂不支持');
  }
})();

export default getImageInfo;