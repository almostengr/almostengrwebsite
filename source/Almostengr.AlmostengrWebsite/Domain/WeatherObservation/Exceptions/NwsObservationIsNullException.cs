using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    [Serializable]
    internal class NwsObservationIsNullException : Exception
    {
        public NwsObservationIsNullException()
        {
        }

        public NwsObservationIsNullException(string message) : base(message)
        {
        }
    }
}