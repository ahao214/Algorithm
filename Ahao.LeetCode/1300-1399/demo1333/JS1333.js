﻿var filterRestaurants = function (restaurants, veganFriendly, maxPrice, maxDistance) {
    const filtered = restaurants.filter(item => item[3] <= maxPrice && item[4] <= maxDistance && !(veganFriendly && !item[2]));
    filtered.sort((a, b) => a[1] == b[1] ? b[0] - a[0] : b[1] - a[1]);
    return filtered.map(item => item[0]);
};
