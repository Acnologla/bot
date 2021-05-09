open CommandRegister
open Discord
let register = () => {
  name: ["avatar"],
  description: "Veja o avatar de alguem",
  run: (message, _) => {
    let user = Utils.getUser(message)
    Embed.create()
    |> Embed.title(user.tag)
    |> Embed.image({url: User.avatarURL(user)})
    |> toEmbed
    |> Message.reply(message)
  }
}
