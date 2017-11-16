// WNixalo - 2017-Nov-15 23:22 - UD989 JavaScript Design Patterns
// Lesson 1: Cat Clicker

// If you're writing Cat Clicker with vanilla JS (no jQuery), you'll be adding the "click" event with elem.addEventListener().
// var count = 0;
// var elem = document.getElementById('cat');
// elem.addEventListener('click', function(){
//   //the element has been clicked... do stuff here
//   count += 1;
//   alert(count);
// }, false);

var count = 0;
$("#cat").click(function() {
    count++;
    alert(count);
});
