var site = {"sites":[
    {"name":"Runoob", "url":"www.runoob.com"}, 
    {"name":"Google", "url":"www.google.com"},
    {"name":"Taobao", "url":"www.taobao.com"}
]};

var blobJson = new Blob([{"sites":[
    {"name":"Runoob", "url":"www.runoob.com"}, 
    {"name":"Google", "url":"www.google.com"},
    {"name":"Taobao", "url":"www.taobao.com"}
]}], {type : 'application/json'});
var blobHtml = new Blob(['<a id="a"><b id="b">hey!</b></a>'], {type : 'text/html'});

var reader = new FileReader;
reader.readAsText(blobHtml, "utf-8");
reader.onload = function(e) {
    console.log('blob: ' + reader.result);
};