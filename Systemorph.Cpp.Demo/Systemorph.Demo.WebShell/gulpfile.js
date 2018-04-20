/// <binding AfterBuild='build' Clean='clean' />

require('app-module-path').addPath(__dirname + '/node_modules');
const gulp = require('gulp');
const gulpBuildConfig = require('./gulpBuildConfig.json');
const cleanTask = require(gulpBuildConfig.gulpTasksDir + 'clean');
const watchTask = require(gulpBuildConfig.gulpTasksDir + 'watch');
const buildTask = require(gulpBuildConfig.gulpTasksDir + 'build');

gulp.task("clean", cleanTask(gulp, gulpBuildConfig));

gulp.task("build", buildTask(gulp, gulpBuildConfig));

gulp.task("watch", watchTask(gulp, gulpBuildConfig));