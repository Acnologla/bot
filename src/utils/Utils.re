open Discord
open Message

let getUser = message => message.mentions.users.size > 0 ?  Collection.first(message.mentions.users) : message.author