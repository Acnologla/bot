let parse = (content) => {
    let splited = String.lowercase_ascii(content) 
    |> Js.String.split(" ") 
    Array.sub(splited, 1, Array.length(splited) - 1)      
}