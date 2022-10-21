using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.WeatherObservation.Exceptions
{
    [Serializable]
    internal class JsonResultIsNullOrWhiteSpaceException : Exception
    {
        public JsonResultIsNullOrWhiteSpaceException()
        {
        }

        public JsonResultIsNullOrWhiteSpaceException(string? message) : base(message)
        {
        }

        public JsonResultIsNullOrWhiteSpaceException(string? message, Exception? innerException) : base(message, innerException)
        {
        }

        protected JsonResultIsNullOrWhiteSpaceException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}