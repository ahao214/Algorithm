function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

var removeNodes = function (head) {
    if (head == null) {
        return null;
    }
    head.next = removeNodes(head.next);
    if (head.next != null && head.val < head.next.val) {
        return head.next;
    } else {
        return head;
    }
};


var removeNodes = function (head) {
    let st = new Array();
    for (; head != null; head = head.next) {
        st.push(head);
    }
    for (; st.length > 0; st.pop()) {
        if (head == null || st[st.length - 1].val >= head.val) {
            st[st.length - 1].next = head;
            head = st[st.length - 1];
        }
    }
    return head;
};



var reverse = function (head) {
    let dummy = new ListNode();
    while (head != null) {
        let p = head;
        head = head.next;
        p.next = dummy.next;
        dummy.next = p;
    }
    return dummy.next;
};

var removeNodes = function (head) {
    head = reverse(head);
    for (let p = head; p.next != null;) {
        if (p.val > p.next.val) {
            p.next = p.next.next;
        } else {
            p = p.next;
        }
    }
    return reverse(head);
};
