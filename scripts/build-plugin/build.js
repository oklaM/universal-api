const path = require('path');
const compose = require('koa-compose');
const fs = require('fs-extra');
const rollupRelease = require('./rollup/build');
const webpackRelease = require('./webpack/build');
const buildMain = require('./buildMain');
const rm = require('rimraf');

module.exports = (api ,options = {}) => {
  const { context, onHook } = api;
  const { commandArgs, rootDir } = context;
  const getItemOutputPath = (name, dir = 'lib/') => dir + name + '/';
  let taskList = [];
  let entry;
  let output;
  let pkgInfo;
  let defaultApiInfo = {
    buildPkgJson: true,
    mvReadme: true,
    declaration: true
  };
  let apiInfo;
  let sourceMap;
  let isMain = false;
  if (commandArgs.api) {
    const outputDir = 'dist/';
    const apiName = commandArgs.api;
    sourceMap = require(path.resolve(rootDir, 'api-config.js'));
    if (apiName === 'main') {
      isMain = true;
      const mainPkg = require(path.resolve(rootDir, 'package.json'));
      entry = path.resolve(rootDir, 'packages/main/index.ts');
      pkgInfo = {
        version: mainPkg.version,
        name: mainPkg.name,
      };
      output = outputDir + 'main/';
      apiInfo = {...defaultApiInfo, unNeedSplit: false};

      buildMain(rootDir, sourceMap);
      
    } else {
      entry = path.resolve(rootDir, sourceMap[apiName].path);
      apiInfo = {...defaultApiInfo, ...sourceMap[apiName]};
      // ourDir = getItemOutputPath(i.name, sourceMap[apiName].outputDir);
      if (Array.isArray(sourceMap[apiName].pkgInfo)) {
        sourceMap[apiName].pkgInfo.forEach(i => {
          pkgInfo = i;
          output = outputDir + getItemOutputPath(i.name, sourceMap[apiName].outputDir);
        });
      } else {
        pkgInfo = sourceMap[apiName].pkgInfo;
        output = outputDir + getItemOutputPath(sourceMap[apiName].pkgInfo.name, sourceMap[apiName].outputDir);
      }
    }
    
  } else {
    entry = options.entry;
    pkgInfo = options.pkgInfo;
    output = options.output;
    apiInfo = {
      buildPkgJson: options.buildPkgJson,
      mvReadme: options.mvReadme,
      declaration: options.declaration,
      unNeedSplit: options.unNeedSplit,
    };
    sourceMap = null;
  }
  rm.sync(path.resolve(rootDir, output));
  webpackRelease(api, {
    entry,
    output,
    sourceMap,
    pkgInfo,
    apiInfo,
    isMain
  });
  taskList.push(
    rollupRelease(entry, pkgInfo, output, sourceMap, apiInfo, isMain)
  );
  onHook('after.build.compile', () => {
    compose(taskList)().then(function() {
      // logger('END', {status: 'SUCCESS'});
    }).catch(function(err) {
      console.log(err);
    });
  });
}