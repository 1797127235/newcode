/**
 * @param {string} s
 * @return {boolean}
 */
var doesAliceWin = function(s) {
    ts = ['a','e','i','o','u']
    let cnt = 0
    for(let c of s)
    {
        if(ts.includes(c)) cnt+=1
    }
    if(cnt == 0) return false
    if(cnt%2) return true
    if((cnt - 1) % 2) return true

    return false


};

//没什么好说的，随便推两个例子就出来了

