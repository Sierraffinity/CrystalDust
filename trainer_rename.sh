#!/bin/bash -x

OLDNUMBER="${1//[!0-9]/}"
OLDNAME="${1//[0-9]/}"
NEWNUMBER="${2//[!0-9]/}"
NEWNAME="${2//[0-9]/}"

git grep -lw "TRAINER_${NEWNAME^^}${NEWNUMBER:+_$NEWNUMBER}" | xargs sed -i "s/TRAINER_${NEWNAME^^}${NEWNUMBER:+_$NEWNUMBER}/TRAINER_${NEWNAME^^}${NEWNUMBER:+_$NEWNUMBER}_OLD/g"
git grep -lw "TRAINER_${OLDNAME^^}${OLDNUMBER:+_$OLDNUMBER}" | xargs sed -i "s/TRAINER_${OLDNAME^^}${OLDNUMBER:+_$OLDNUMBER}/TRAINER_${NEWNAME^^}${NEWNUMBER:+_$NEWNUMBER}/g"
git grep -lw "sParty_${NEWNAME}${NEWNUMBER}" | xargs sed -i "s/sParty_${NEWNAME}${NEWNUMBER}/sParty_${NEWNAME}${NEWNUMBER}Old/g"
git grep -lw "sParty_${OLDNAME}${OLDNUMBER}" | xargs sed -i "s/sParty_${OLDNAME}${OLDNUMBER}/sParty_${NEWNAME}${NEWNUMBER}/g"
