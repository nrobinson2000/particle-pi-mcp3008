#!/bin/bash
sudo apt install -y expect

curl -sLO https://raw.githubusercontent.com/nrobinson2000/po-util/master/po-util.sh

chmod +x po-util.sh

curl -sLO https://raw.githubusercontent.com/nrobinson2000/po-util/master/config-expect.sh

chmod +x config-expect.sh

./config-expect.sh

./po-util.sh install

po lib clean . -f &> /dev/null
po lib setup
po pi build
