open CommandRegister;
open Discord;
let register = () => {
    name: ["avatar"],
    run: (message, _) =>{
        let user = if (message.mentions.users.size > 0){
            Collection.first(message.mentions.users);
        } else {
            message.author;
        };
        let embed = Embed.create()
        |> Embed.title(user.tag)
        |> Embed.image({url: User.avatarURL(user)});
        Message.replyEmbed(message, {embed: embed});
    }
};