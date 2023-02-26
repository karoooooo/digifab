function hideMenu (){
 const hamburger = document.getElementById("nav-list");
 if(hamburger.style.display === "flex"){
  hamburger.style.display = "none";
 } else {
  hamburger.style.display = "flex";
 }
}

function toggleContent (){
  const codeBlock = document.getElementById("toggle-code");
  if(codeBlock.style.display === "flex"){
    codeBlock.style.display = "none";
   } else {
    codeBlock.style.display = "flex";
   }
}
