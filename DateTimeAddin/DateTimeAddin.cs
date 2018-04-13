using System.Globalization;
using Arma3Net;
using SDateTime = System.DateTime;

namespace DateTimeAddin
{
    [Addin("DateTime", Author = "Scott_NZ", Description = "Date and time utilities")]
    public class DateTime : Addin
    {
        public override string Invoke(string args, int maxResultSize)
        {
            var split = (args ?? "").Split(',');
            var dateTime = split[0] == "now" ? SDateTime.Now : SDateTime.UtcNow;
            var format = split.Length > 1 ? split[1] : "G";
            return dateTime.ToString(format, CultureInfo.InvariantCulture);
        }
    }
}
