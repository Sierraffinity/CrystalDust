#!/bin/bash -x

NUMBER="${1//[!0-9]/}"
NAME="${1//[0-9]/}"

git grep -lw "TRAINER_${2^^}" | xargs sed -i "s/TRAINER_${2^^}/TRAINER_${2^^}_OLD/g"
git grep -lw "TRAINER_${NAME^^}_$NUMBER" | xargs sed -i "s/TRAINER_${NAME^^}_$NUMBER/TRAINER_${2^^}/g"
git grep -lw "sParty_$2" | xargs sed -i "s/sParty_$2/sParty_$2Old/g"
git grep -lw "sParty_$NAME$NUMBER" | xargs sed -i "s/sParty_$NAME$NUMBER/sParty_$2/g"
