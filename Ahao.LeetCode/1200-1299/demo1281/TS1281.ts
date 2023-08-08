function subtractProductAndSum(n: number): number {
    const list = n.toString().split('');
    let mul = 1;
    let sum = 0;
    for (let i of list) {
        const num = Number(i);
        mul *= num;
        sum += num;
    }
    return mul - sum;
};
