﻿var haveConflict = function (event1, event2) {
    return !(event1[1] < event2[0] || event2[1] < event1[0]);
};
