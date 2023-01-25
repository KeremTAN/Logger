# Logger
With this logging class, you will be able to log daily, hourly, minute and second, and create a separate log file for each date. The naming of the log files will be the UTC format of that date.

The created log files will be in the **logs** directory.

You can control the number of log files, the frequency of occurrence and the type of log that will be created in this application.

You can change the data in the **configs/config.json** file to set the properties mentioned above.

You can change the variable maxLogFiles to set the number of log files. According to the value here, your old log files will be deleted as new log files are added.

You can change the variable logFrequency to set the frequency of occurrence of log files. File occurrence frequencies are **second**, **minute**, **hourly** and **daily**.

You can change the variable logLevel to set the level of the logged log files. Log levels are **warn**, **info**, **debug** and **error**.

Example of config.json
```json
{
    "maxLogFiles":  3,
    "logFrequency": "second",
    "logLevel":     "warn"
}
```

<!-- ![UML](https://github.com/KeremTAN/Logger/blob/main/img/terminal.png) -->
