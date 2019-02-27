Template and CUDA
====================
## Template Basics
### Function Templates
### Class Templates
### Non Type Template Parameters
### Specialization
### Template as Template Parameter
## Template Based Patterns
### Traits
### Policies
### Metaprogram
### Expression Template
## Template Based Design
### Name
Naming is really important here, because as default every thing is public.
Usually, local parameters are "xxx\_" includes template parameters / parameters / non public members. 
### Parameters or Template Parameters
At the beginning of design which parameters go into template parameters is an important questions. This question equals to "what parameters can be determined during compiling". Therotically, everything about optimization / type / or related to such two things can be put into template paramter list. A good reference is cutlass::gemm 
### If Not Necessary Don't Make Instantiation
Instantiation is expensive. If possible don't create object (pass by parameters). Also the instantiation of a template always limit flexibility
## CUDA and Template
### High Efficiency

