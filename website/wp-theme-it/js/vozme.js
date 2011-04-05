function create_form(d,txt,lang,gn,tgt){
fx_2g=d.createElement('form');
d.body.appendChild(fx_2g);
fx_2g.target=tgt;
fx_2g.method='POST';
fx_2g.action='http://vozme.com/text2voice.php';
//text
t=d.createElement('input');
t.name='text';
t.type='hidden';
t.value=txt;
fx_2g.appendChild(t);
//lang
l=d.createElement('input');
l.name='lang';
l.type='hidden';
l.value=lang;
fx_2g.appendChild(l);
//gn
g=d.createElement('input');
g.name='gn';
g.type='hidden';
g.value=gn;
fx_2g.appendChild(g);
//interface
i=d.createElement('input');
i.name='interface';
i.type='hidden';
i.value='full';
fx_2g.appendChild(i);
//submit
window.open('', tgt, 'width=600,height=370,scrollbars=yes,location=yes,menubar=yes,resizable=yes,status=yes,toolbar=yes'); 
fx_2g.submit();
delete fx_2g;
return false;
}

function get_selection(){
var lang = arguments[0] || '';
var gn = arguments[1] || '';
var tgt='voice_'+parseInt(Math.random()*100000);
var d=window.document;
if(window.getSelection){
 txt=window.getSelection();
} else if(d.getSelection){
 txt=d.getSelection();
} else if(d.selection){
 txt=d.selection.createRange().text;
} else{
 txt='';
}
create_form(d,txt,lang,gn,tgt);
return false;
}


function get_id(id){
var lang = arguments[1] || '';
var gn = arguments[2] || '';
var tgt= arguments[3] || 'voice_'+parseInt(Math.random()*100000);
var d=window.document;
var txt='';
txt=d.getElementById(id).innerHTML;
create_form(d,txt,lang,gn,tgt);
return false;
}


function get_blogger(id){
var lang = arguments[1] || '';
var gn = arguments[2] || '';
var tgt='voice_'+parseInt(Math.random()*100000);
var d=window.document;
var txt='';
pN=d.getElementsByName(id)[0].parentNode;
for(n=0;n<pN.childNodes.length;n++){
    if(pN.childNodes[n].className == 'post-title entry-title' || pN.childNodes[n].className == 'post-title' || pN.childNodes[n].className == 'post-body entry-content' || pN.childNodes[n].className == 'post-body'){
        txt=txt + ' ' + pN.childNodes[n].innerHTML;
    }
}
create_form(d,txt,lang,gn,tgt);
return false;
}
