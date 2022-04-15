// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
function NestedInteger() {

    Return true if this NestedInteger holds a single integer, rather than a nested list.
      @return { boolean }
    this.isInteger = function () {
          ...
    };

    Return the single integer that this NestedInteger holds, if it holds a single integer
    Return null if this NestedInteger holds a nested list
    @return { integer }
    this.getInteger = function () {
          ...
    };

    Set this NestedInteger to hold a single integer equal to value.
      @return { void}
    this.setInteger = function (value) {
          ...
    };

    Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
      @return { void}
    this.add = function (elem) {
          ...
    };

    Return the nested list that this NestedInteger holds, if it holds a nested list
    Return null if this NestedInteger holds a single integer
    @return { NestedInteger[]}
    this.getList = function () {
          ...
    };
};

var deserialize = function (s) {
    let index = 0;
    const dfs = (s) => {
        if (s[index] === '[') {
            index++;
            const ni = new NestedInteger();
            while (s[index] !== ']') {
                ni.add(dfs(s));
                if (s[index] === ',') {
                    index++;
                }
            }
            index++;
            return ni;
        } else {
            let negative = false;
            if (s[index] === '-') {
                negative = true;
                index++;
            }
            let num = 0;
            while (index < s.length && isDigit(s[index])) {
                num = num * 10 + s[index].charCodeAt() - '0'.charCodeAt();
                index++;
            }
            if (negative) {
                num *= -1;
            }
            return new NestedInteger(num);
        }
    }
    return dfs(s);
};

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}
