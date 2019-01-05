# VexTurningPoint2019

UML Robotics Club's Vex Turning Point code for our 15 inch robot named Swift


## Building
### Install dependencies
You need:
* git
* make
* gcc-arm-none-eabi
* python3
* python3-pip

Install the arm cross compiler
```shell
#for debian based distros
sudo apt-get install gcc-arm-none-eabi
```

Install pros-cli3
```shell
git clone https://github.com/purduesigbots/pros-cli3.git
cd pros-cli3
sudo pip install -e .
```

Clone the repo
```shell
git clone https://github.com/UMLRoboticsClub/VexTurningPoint2019_Swift.git
```

## Build the project
```shell
cd VexTurningPoint2019_Swift
make
```

## Uploading your code
```shell
prosv5 upload
```

## Open serial connection with the V5
```shell
prosv5 terminal
```
