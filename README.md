```
       ...                                                    ..                        
   .x888888hx    :                                      < .z@8"`        ..              
  d88888888888hxx     u.    u.                           !@88E         @L               
 8" ... `"*8888%`   x@88k u@88c.      .u          u      '888E   u    9888i   .dL       
!  "   ` .xnxx.    ^"8888""8888"   ud8888.     us888u.    888E u@8NL  `Y888k:*888.      
X X   .H8888888%:    8888  888R  :888'8888. .@88 "8888"   888E`"88*"    888E  888I      
X 'hn8888888*"   >   8888  888R  d888 '88%" 9888  9888    888E .dN.     888E  888I      
X: `*88888%`     !   8888  888R  8888.+"    9888  9888    888E~8888     888E  888I      
'8h.. ``     ..x8>   8888  888R  8888L      9888  9888    888E '888&    888E  888I      
 `88888888888888f   "*88*" 8888" '8888c. .+ 9888  9888    888E  9888.  x888N><888'      
  '%8888888888*"      ""   'Y"    "88888%   "888*""888" '"888*" 4888"   "88"  888       
     ^"****""`                      "YP'     ^Y"   ^Y'     ""    ""           88F       
                                                                             98"        
                                                                           ./"          
                                                                          ~`            
       ...                          .                    ..                             
   .x888888hx    :                 @88>            < .z@8"`                             
  d88888888888hxx     u.    u.     %8P              !@88E                      .u    .  
 8" ... `"*8888%`   x@88k u@88c.    .          .    '888E   u         .u     .d88B :@8c 
!  "   ` .xnxx.    ^"8888""8888"  .@88u   .udR88N    888E u@8NL    ud8888.  ="8888f8888r
X X   .H8888888%:    8888  888R  ''888E` <888'888k   888E`"88*"  :888'8888.   4888>'88" 
X 'hn8888888*"   >   8888  888R    888E  9888 'Y"    888E .dN.   d888 '88%"   4888> '   
X: `*88888%`     !   8888  888R    888E  9888        888E~8888   8888.+"      4888>     
'8h.. ``     ..x8>   8888  888R    888E  9888        888E '888&  8888L       .d888L .+  
 `88888888888888f   "*88*" 8888"   888&  ?8888u../   888E  9888. '8888c. .+  ^"8888*"   
  '%8888888888*"      ""   'Y"     R888"  "8888P'  '"888*" 4888"  "88888%       "Y"     
     ^"****""`                      ""      "P'       ""    ""      "YP'
```

C Script to encrypt and decrypt binary files using AES-128

#### Appreciation
If you clone the repo don't forget to give a little star!

#### Usage
File should be where the script is running.

1. Random generate your key and replace it on the script

`openssl rand -hex 16` or `python3 -c "import secrets; print(secrets.token_hex(16))"`

2. Compile it.
   
`gcc -o sneakysnicker sneakysnicker.c -lssl -lcrypto`

3. Run it
   
`./sneakysnicker`
