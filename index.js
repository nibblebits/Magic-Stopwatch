// Modules to control application life and create native browser window
const { app, Notification, ipcMain, webContents} = require("electron");
module.exports = require("bindings")("addon");
const NOTIFICATION_TITLE = "Basic Notification";
const NOTIFICATION_BODY = "Notification from the Main process";

const assert = require("assert");
const { increment } = require(".");
const { createMainWindow } = require("./windowManager");

// ...

app.whenReady().then(() => {
  createMainWindow();

  let counter = 0;

  setInterval(() => {
    counter++;
    webContents.getAllWebContents().forEach(contents => {
      contents.send('counterUpdated', counter);
    });
  }, 1000);

  ipcMain.on('getCounter', (event) => {
    event.returnValue = counter;
  });

  // ...
});

// ...
