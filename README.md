# Logger
* [Summary Information](#si)
* [config.json](#config)
* [JsonParser & Logger](#jl)
    * [Code example using JsonParser and Logger objects;](#exm)
* [Example Image of Terminal](#img)

<a name="si"></a>
With this logging class, you will be able to log daily, hourly, minute and second, and create a separate log file for each logging. The naming of the log files will be the UTC format of that date. If the number of log files you keep is more than the maximum number you set, your oldest log file will be deleted by automatically.

The created log files will be in the **logs** directory.

You can control the number of log files, the frequency of occurrence and the type of log that will be created in this application.

<a name="config"></a>
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
<a name="jl"></a>
There is one JsonParse class for parsing the json object shown in the above example. You just need to give the path of your json file to the constructor of this class.

I have added nlohmann's json library to this project in case you need a professional json library. You can use that library directly if you wish.
For detailed information about nlohmann's json library, go to the link (https://github.com/nlohmann/json).

However, if you use nlohmann's library, you will need to convert the data that you parse into **LogFrequency and LogLevel types** with **Frequency and Level namespaces**.
```c++
    LogFrequency    logFrequency = Frequency::convert(j["logFrequency"]);
    LogLevel        logLevel = Level::convert(j["logLevel"]);
```

After parsing the data in the config.json file, you need to create a Logger object. While creating the Logger class, its constructor expects 4 parameters. These parameters are respectively maximum number of files, log file creation frequency, log level and a bool value for pressing the terminal while saving the logs. If these parameters are not entered while creating the Logger object, these parameters will work with their default values.

After the logger object is created, you just need to call the log method.

<a name="exm"></a>
Code example using JsonParser and Logger objects;
```c++
int main(int argc, char** argv){
  JsonParser json("/configs/config.json");

  int maxLogFiles = json.getMaxLogFiles();
  LogFrequency logFrequency = json.getLogFrequency();
  LogLevel logLevel = json.getLogLevel();

  Logger logger(maxLogFiles, logFrequency, logLevel, true); 
  logger.log("This is a log about logger");

  std::cin.get();
}
```
<a name="img"></a>
An example image of the terminal outputs you will get when you use this log application; </br>
 ![UML](https://github.com/KeremTAN/Logger/blob/main/img/terminal.png)