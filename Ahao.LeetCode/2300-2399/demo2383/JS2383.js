﻿var minNumberOfHours = function (initialEnergy, initialExperience, energy, experience) {
    let sum = 0;
    for (const e of energy) {
        sum += e;
    }
    let trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
    for (const e of experience) {
        if (initialExperience <= e) {
            trainingHours += 1 + (e - initialExperience);
            initialExperience = 2 * e + 1;
        } else {
            initialExperience += e;
        }
    }
    return trainingHours;
};
