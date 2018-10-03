# VexTurningPoint2019

UML Robotics Club's Vex Turning Point code


## Building
### Install dependencies
You need:
* git
* make
* gcc-arm-none-eabi
* python3
* python3-pip

Install pros-cli3
```shell
git clone https://github.com/purduesigbots/pros-cli3.git
cd pros-cli3
sudo pip install -e .
```

Clone the repo
```shell
git clone https://github.com/UMLRoboticsClub/VexTurningPoint2019.git
```

## Build the project
```shell
cd VexTurningPoint2019
make
```

## Uploading your code
```shell
prosv5 upload
```

## Open serial connection with cortex
```shell
prosv5 terminal
```
