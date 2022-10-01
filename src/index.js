function hideMenu (){
 const hamburger = document.getElementById("nav-list");

 if(hamburger.style.display === "flex"){
  hamburger.style.display = "none";
 } else{
  hamburger.style.display = "flex";
 }
}


/* 

General: Nav, if it doesn't have an a-attribute, hide it

MOBILE: 

clicked nav hamburger-menu
sliding nav from the side, moving "main" down

DESKTOP:
hamburger-menu hidden

hover nav: menu items appearing 

"id=about" clicked in desktop
redirected to about in main (opening it)

*/
